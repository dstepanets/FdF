# FdF

![](fdf_demo.gif)

## Description

3D graphics program. Draws a wireframe model of a relief landscape. Takes as input a map in form of a text document where space separated integers represent vertices of a model. The integer's position defines Y and X coordinate, and its value is for Z coordinate.

*This is the first project in the graphics branch of School 42 curriculum.*

**Detailed description of a task is in [fdf.en.pdf](https://github.com/dstepanets/FdF/blob/master/fdf.en.pdf)**

## Usage

Compile with `make`. Then run:

`./fdf [map.fdf]`

There is the maps directory with examples.

*Tested only on Mac OS X.*

## Features

- scroll
- zoom
- rotation (manual and auto)
- color gradient relative to altitude
- iso and parallel projections switch
- relief sharpness modification (Z coordinate scaling)
