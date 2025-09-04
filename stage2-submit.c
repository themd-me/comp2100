#include <stdint.h>
#include <inttypes.h>

//Defining booleans with size
typedef int32_t bool32;
typedef int16_t bool16;
typedef int8_t bool8;

struct myStruct {
        bool32 territory;
        int volleyball;
        char partner[7];
        double sidewalk;
        char trucks;
        uint8_t trip;
        float band;
        bool8 digestion;
        bool32 bubble;
        bool16 nest;
        bool16 note;
        uint16_t touch;
        int8_t sun;
        int birthday;
        int64_t wealth;
        bool32 hospital;
        float drum;
};

int main(int argc, char *argv[])
{
    // open the file in rb mode
    FILE* file = fopen(argc[0], "rb");

    // check if the file was successfully opened
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Define the struct
    struct myStruct m;

    // Read the structs present in the file
    while (fread(&m, sizeof(myStruct), 1, file)
           == 1) {
        
        printf("territory, volleyball, partner, sidewalk, trucks, trip, band, digestion, bubble, nest, note, touch, sun, birthday, wealth, hospital, drum\n");
        printf("%d, %d, %s, ", m.territory, m.volleyball, m.partner);
        printf("%.6f, %c, %i, ", m.sidewalk, m.trucks, m.trip);
        printf("%.6f, %d, %d, ", m.band, m.digestion, m.bubble);
        printf("%d, %d, %d, ", m.nest, m.note, m.touch);
        printf("%i, %i, ", m.sun, m.birthday);
        printf("%016" PRIx64 ", ", (uint64_t)m.wealth);
        printf("%d, %.6f\n", m.hospital, m.drum);
        return 0;
    }

    // close the file
    fclose(file);
    return 0;
}