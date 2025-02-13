# File Organizer

Una herramienta de línea de comandos simple para organizar archivos automáticamente por extensión. Desarrollada en C.

## Características

- Organiza archivos automáticamente en carpetas según su extensión
- Crea automáticamente las carpetas necesarias
- Mantiene la estructura limpia y ordenada
- Ideal para organizar carpetas de descargas
- Muestra información en tiempo real de los archivos movidos
- Fácil de usar desde la terminal

## Instalación (GitHub Codespaces)

1. Abre el proyecto en GitHub Codespaces

2. Compila el programa:
```bash
gcc -Wall -Wextra -o organizer src/main.c
```

## Instalación (Local)

1. Clona el repositorio:
```bash
git clone https://github.com/EduardoHernandezGuzman/file-organizer.git
cd file-organizer
```

2. Compila el programa:
```bash
gcc -Wall -Wextra -o organizer src/main.c
``` 

## Uso

1. Ejecuta el programa especificando el directorio a organizar:
```bash
./organizer <directorio>
``` 

Ejemplo:
```bash
./organizer ~/Downloads
```

El programa:
- Creará subcarpetas para cada tipo de archivo (jpg, pdf, doc, etc.)
- Moverá cada archivo a su carpeta correspondiente
- Mostrará el progreso en tiempo real

## Tecnologías utilizadas
- C
- Bibliotecas estándar de C:
- stdio.h
- stdlib.h
- string.h
- dirent.h
- sys/stat.h
- sys/types.h

## Requisitos
- Compilador GCC
- Sistema operativo compatible con POSIX (Linux, macOS)

## Precauciones
- Se recomienda hacer una copia de seguridad antes de organizar carpetas importantes
- El programa mueve los archivos (no los copia)

## Contribuir
Las contribuciones son bienvenidas. Siéntete libre de abrir issues o pull requests para mejorar este proyecto.

## Contacto

Para cualquier consulta o colaboración, puedes contactar al autor a través de:

- GitHub: [EduardoHernandezGuzman](https://github.com/EduardoHernandezGuzman)

## Licencia
Este proyecto está bajo la Licencia MIT.
