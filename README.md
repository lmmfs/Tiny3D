# Tiny3D
a lightweight C++ game engine for the 3Ds platform

# dependencies

## devkitpro container

The project has a dockerfile to setup and create a docker container with devkitpro

```bash
    docker build -t tiny3d-dev -f devkit-container/Dockerfile .
    docker run --rm -it -v $(pwd):/workspace tiny3d-dev
```

## Alternative

Install devkitpro following the guide https://devkitpro.org/wiki/devkitPro_pacman
