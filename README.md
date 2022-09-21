# so_long

##General requirements
MLX lib provided by 42 is required. In this repository you will find the steps to get mlx in linux. You can apply the instructions to iOS.

###Requirements on Linux
To play; xorg, x11 and zlib whose dependencies are: xorg, libxext-dev and zlib1g-dev. You can install them by running the following command:
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
Once the dependencies are installed, you may copy or move libmlx.a and/or libmlx_Linux.a in /usr/local/lib. These files are inside Linux/minilibLinux in this repository.

Then you can go inside Linux directory and run this two commands:
```bash
make
./so_long ./maps/2.ber
```
in the case you want to play map number 2. There are 3.

##Disclaimer
All mlx functions was developed by 42 school.
The image in this game was processed with gimp. In Linux images have low quality.
