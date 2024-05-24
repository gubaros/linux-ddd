# Linux Device Dummy Driver

Este proyecto contiene varios ejemplos de controladores de dispositivo para el kernel de Linux. Cada uno de los ejemplos muestra diferentes técnicas para interactuar con el kernel. A continuación se describen los programas en C incluidos en este repositorio:

## Archivos

- `driver.c`: El código fuente para el controlador básico del dispositivo.
- `device.c`: El código fuente para el controlador de dispositivo de caracteres.
- `kernel_timer.c`: El código fuente para el controlador del dispositivo utilizando un temporizador.
- `Makefile`: El archivo de make para construir los módulos del kernel.
- `test.sh`: Un script de prueba simple para cargar y descargar el módulo.

## Requisitos

Asegúrate de tener instalados los headers del kernel necesarios. En sistemas basados en Debian, puedes instalarlos con:

```sh
sudo apt-get install linux-headers-$(uname -r)

```sh
git clone https://github.com/gubaros/linux-ddd
cd linux-ddd
aclocal
autoconf
automake --add-missing
./configure
make
sudo make install
./test.sh
