#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Función para crear directorios
void createDirectory(const char *path) {
   #ifdef _WIN32
       _mkdir(path);
   #else
       mkdir(path, 0777);
   #endif
}

// Función para obtener la extensión de un archivo
char* getFileExtension(const char *filename) {
   char *dot = strrchr(filename, '.');
   if(!dot || dot == filename) return "";
   return dot + 1;
}

int main(int argc, char *argv[]) {
   if (argc != 2) {
       printf("Uso: ./organizer <directorio>\n");
       return 1;
   }

   DIR *dir;
   struct dirent *entry;
   char path[1024];
   char destPath[1024];

   // Abrir el directorio
   dir = opendir(argv[1]);
   if (dir == NULL) {
       printf("No se pudo abrir el directorio\n");
       return 1;
   }

   printf("Organizando archivos en: %s\n", argv[1]);

   // Leer el contenido del directorio
   while ((entry = readdir(dir)) != NULL) {
       if (entry->d_type == DT_REG) {  // Si es un archivo regular
           char *ext = getFileExtension(entry->d_name);
           if (strlen(ext) > 0) {
               // Crear directorio para la extensión
               snprintf(path, sizeof(path), "%s/%s", argv[1], ext);
               createDirectory(path);

               // Construir rutas
               snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
               snprintf(destPath, sizeof(destPath), "%s/%s/%s", 
                       argv[1], ext, entry->d_name);
               
               // Mover archivo
               if (rename(path, destPath) == 0) {
                   printf("✓ Movido: %s -> %s\n", entry->d_name, ext);
               }
           }
       }
   }

   closedir(dir);
   printf("\n¡Organización completada!\n");
   return 0;
}