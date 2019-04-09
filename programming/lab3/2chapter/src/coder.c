#include "coder.h"

int encode(uint32_t code_point, CodeUnits* code_units)
{
    uint8_t* cur = code_units->code;
    while (code_point >= 0x80) {
        const uint8_t byte = (code_point & 0x7f) | 0x80;
        *cur = byte;
        code_point >>= 7;
        ++cur;
    }
    *cur = code_point;
    ++cur;
    code_units->length = cur - code_units->code;
    return 0;
}

uint32_t decode(const CodeUnits* code_unit)
{
    const uint8_t* cur = code_unit->code;
    uint8_t byte = *cur++;
    uint32_t value = byte & 0x7f;
    size_t shift = 7;
    while (byte >= 0x80) {
        byte = *cur++;
        value += (byte & 0x7f) << shift;
        shift += 7;
    }
    return value;
}

int read_next_code_unit(FILE* in, CodeUnits* code_units)
{
    size_t _length = 20;
    size_t result_count = 0;
    uint32_t code;
    char* a = (char*)malloc(sizeof(char) * _length);
    do {
        if (_length == result_count) {
            _length = _length * 2;
            a = (char*)realloc(a, sizeof(char) * _length);
        }
        if (fscanf(in, "%c", &a[result_count]) != 1) {
            fprintf(stderr, "fscanf return non-1\n");
            return 2;
        }
    } while (a[result_count++] != '\n');
    a[result_count - 1] = '\0';
    code = atoi(a);
    // printf("Read string : %s\n", a);
    encode(code, code_units);
    return 0;
}

int write_code_unit(FILE* out, const CodeUnits* code_unit)
{
    //В какой области писать, размер считываемого блока, длина блока, файл)
    fwrite(&code_unit->length, 1, sizeof(code_unit->length), out);
    fwrite(&code_unit->code,
           1,
           sizeof(*code_unit->code) * code_unit->length,
           out);
    return 0;
}

int read_next(FILE* in, CodeUnits* code_units)
{
    int count = 0;
    //куда считать, размур блока, кол-во блоков (бинарно), файловый указатель)
    if ((count = fread(&code_units->length, 1, sizeof(code_units->length), in))
        != sizeof(code_units->length)) {
        fprintf(stderr,
                "END: fread return eof. Count = %d (Expected %lu)\n",
                count,
                sizeof(code_units->length));
        return 2;
    }
    if (fread(&code_units->code,
              1,
              sizeof(*code_units->code) * code_units->length,
              in)
        != sizeof(*code_units->code) * code_units->length) {
        fprintf(stderr,
                "Error: fread return error. Count = %d (Expected %lu)\n",
                count,
                sizeof(*code_units->code) * code_units->length);
        return 1;
    }
    // fprintf(stderr, "Success read value\n");
    return 0;
}

int write_next(FILE* out, const CodeUnits* code_unit)
{
    uint32_t value = decode(code_unit);
    fprintf(out, "%u\n", value);
    return 0;
}
