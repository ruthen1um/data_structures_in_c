#ifndef DATA_H
#define DATA_H

typedef enum DataType {
    IntegerType,
    FloatType,
} DataType;

typedef struct DataStruct {
    DataType type;
    union {
        int i;
        float f;
    };
} DataStruct;

#endif
