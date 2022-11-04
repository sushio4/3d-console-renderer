# 3d-console-renderer
It's a Linux project, that aims to help with 3d rendering in terminal.

It uses characters as pixels and gradient to show depth (maybe in the future I'll add light system...)

# How to use?
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
  

In order to draw the frame, you'd most likely want to clear it with clearFrame() first. As for now, you can draw lines, triangles, and cubes.
To draw something, you must push it to the object buffer.
There are two object buffers, one for lines and the other for triangles, but it should not bother you.
You just pushLine/Triangle/Cube and renderer will put that in an appropriate buffer for you. 
What should bother you, is the fact, that 

//TODO: finish
