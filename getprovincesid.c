#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

// ต้องรวมไฟล์ cJSON.h (สมมติว่าอยู่ในโฟลเดอร์เดียวกัน)
#include "cJSON.h"

// ฟังก์ชันสำหรับอ่านเนื้อหาทั้งหมดของไฟล์ (ใช้โค้ดเดิม)
char *read_file_to_string(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content = (char *)malloc(length + 1);
    if (!content) {
        fclose(fp);
        perror("Memory allocation failed");
        return NULL;
    }

    if (fread(content, 1, length, fp) != length) {
        free(content);
        fclose(fp);
        perror("Error reading file");
        return NULL;
    }
    
    fclose(fp);
    content[length] = '\0';
    return content;
}

// --- 2. ฟังก์ชันหลักสำหรับ Parse และแสดงผล ---
int main() {
    const char *filename = "provinces.json"; // ผมเปลี่ยนกลับเป็น province.json ตามชื่อเดิม
    char *json_string = read_file_to_string(filename);

    if (json_string == NULL) {
        return 1;
    }

    // ----------------------------------------------------
    // --- 3. เริ่มต้นการ Parse JSON ด้วย cJSON ---
    // ----------------------------------------------------
    cJSON *root_array = cJSON_Parse(json_string);
    free(json_string);

    if (root_array == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "JSON Error before: %s\n", error_ptr);
        }
        return 1;
    }

    if (!cJSON_IsArray(root_array)) {
        fprintf(stderr, "JSON structure is not an array.\n");
        cJSON_Delete(root_array);
        return 1;
    }

    int array_size = cJSON_GetArraySize(root_array);
    printf("Found %d provinces in JSON file.\n", array_size);
    printf("========================================\n");


    // เตรียมตัวแปร Array ของ Struct เพื่อเก็บข้อมูล
    ProvinceData provinces[array_size]; 

    // วน Loop อ่านข้อมูลทีละ Object
    for (int i = 0; i < array_size; i++) {
        cJSON *province_object = cJSON_GetArrayItem(root_array, i);

        if (cJSON_IsObject(province_object)) {
            // ดึงค่าแต่ละ field
            cJSON *id_item = cJSON_GetObjectItemCaseSensitive(province_object, "id");
            cJSON *pCode_item = cJSON_GetObjectItemCaseSensitive(province_object, "provinceCode");
            cJSON *pNameEn_item = cJSON_GetObjectItemCaseSensitive(province_object, "provinceNameEn");
            
            // ตรวจสอบและบันทึกข้อมูลเข้า struct
            if (cJSON_IsNumber(id_item)) {
                provinces[i].id = id_item->valueint;
            }
            if (cJSON_IsNumber(pCode_item)) {
                provinces[i].provinceCode = pCode_item->valueint;
            }
            if (cJSON_IsString(pNameEn_item)) {
                strncpy(provinces[i].provinceNameEn, pNameEn_item->valuestring, 49);
                provinces[i].provinceNameEn[49] = '\0';
            }

            // **********************************************
            // *** แสดงผลเฉพาะภาษาอังกฤษและ Code เท่านั้น ***
            // **********************************************
            printf("Province #%d\n", provinces[i].id);
            printf("  Code: %d\n", provinces[i].provinceCode);
            printf("  Name (EN): %s\n", provinces[i].provinceNameEn);
        }
    }

    // ล้างหน่วยความจำของ cJSON object
    cJSON_Delete(root_array);
    
    printf("========================================\n");
    printf("--- Province Data Reading Complete ---\n");

    return 0;
}