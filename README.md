# 3d-console-renderer

It's a Linux project, that aims to help with 3d rendering in terminal.

It uses characters as pixels and gradient to show depth (maybe in the future I'll add light system...)

## How to use?
### Initialisation
Create Renderer object at the beginning, you can change some attributes such as:
- enable/disableDepthTest()

  As the name suggests. If disabled, it'll draw in whatever order you push your shapes.
  
  It's disabled by default
 
- enable/disableOrtho()

  Enables or disables orthogtaphic projection.
  
  When enabled, you get your regular 3d projection. When disabled, everything is like in 2d.
  
  Disabled by default
  
- setEyeDistance(double dist)
 
  Takes said distance as an argument. It's just for orthographic projection.
  
  Equals 1 by default
  
### Drawing 
#### Clearing
In order to draw the frame, you'd most likely want to clear it with clearFrame() first.
Aside from that, you should also clear object buffers

#### Transformations
Now it's time for some transformations.
Grab some static Matrix4 functions, 
multiply them to have a transformation matrix,
and finally assign it to your renderer object's transformation matrix object.

#### Rendering shapes
As for now, you can draw lines, triangles, and cubes.
To draw something, you must push it to the object buffer.
There are two object buffers, one for lines and the other for triangles, but it should not bother you.
You just pushLine/Triangle/Cube and renderer will put that in an appropriate buffer for you.

In the future there will be more composite shapes aside from that cube.
Now you must write your own. Sorry, I'm busy.

#### Displaying your frame
Now you need two functions. 

The first, renderShapes() renders all the shapes in both object buffers
and puts them in frame buffer.

The second, drawFrame() is the final thing you should do to display your frame 
It simply puts (pun intended) frame buffer on the screen.

### Enjoy!
Enjoy your brand new frame!
You can put that stuff in some loop to make cool animations,
like that cube currently in main.cpp as well as binary release 
