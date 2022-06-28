#include "cJSON.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "stdio.h"
#include "string.h"
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define LOG_TAG "MAIN"



void app_main() {
    while(true){
        char *string = NULL;
        cJSON *name = NULL;
        //cJSON *access = NULL;
        //cJSON *number = NULL;
     
        cJSON *monitor = cJSON_CreateObject();

        name = cJSON_CreateString("Dummy");
        //access = cJSON_CreateBool(false);
        //number = cJSON_CreateNumber(5);

        cJSON_AddItemToObject(monitor, "name", name);
        //cJSON_AddItemToObject(monitor, "access", access);
        //cJSON_AddItemToObject(monitor, "number", number);

        string = cJSON_Print(monitor);
        printf("%s\n",string);
        
    
        ESP_LOGI(LOG_TAG, "NOW PARSING JSON DATA");


        cJSON* root = NULL; 
        cJSON* json_access = NULL;
        cJSON* json_name = NULL;
        char* json_teststring = NULL;
        int json_number = NULL;


        root = cJSON_Parse(string);
        
        
        //json_number = cJSON_GetObjectItem(root,"number")->valueint;

        //json_access = cJSON_GetObjectItem(root,"access");

        json_name = cJSON_GetObjectItem(root,"name");

    
        
        json_teststring = cJSON_PrintUnformatted(json_name);

        ESP_LOGI(LOG_TAG, "%s",json_teststring);

        char* proba = "Dummy";

    
        if(strcmp(json_teststring, proba)==0)
    {
        ESP_LOGI(LOG_TAG, "%s","Dummy data success");
    }
    else{
        ESP_LOGI(LOG_TAG, "%s","Didnt work...");
    }
       

        /*   INT AND BOOL WORKING
    
        if (json_number == 5)
        {
            ESP_LOGI(LOG_TAG,"THIS THING IS FINALLY CONVERTED");
        }

        else{
            ESP_LOGI(LOG_TAG,"NOp");
        }
        
        if (cJSON_IsTrue(json_access)==true)
        {
            ESP_LOGI(LOG_TAG,"TURN OFF LED");
        }
        else{
            ESP_LOGI(LOG_TAG,"TURN ON LED");
        }

        */
       

        cJSON_Delete(root);

        vTaskDelay(10000);
    }




}