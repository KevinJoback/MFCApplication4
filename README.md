This is an example MFC application that duplicates the problem I am having:
when many views, each view having many child windows, are open, dragging 
the main window with the mouse results in delayed movement.

I tried to keep the solution as close to the default generated MDI 
solution as possible. Within visual studio, you should be able to simply 
build the solution and run it.

Once the application is open, create 10 or more views and then try to drag 
the main window around the screen.

I modified the following files/functions:
- ChildWnd.cpp/OnPaint
- ChildWnd.cpp/OnEraseBkgnd
- MFCApplication4View/OnCreate
- MFCApplication4App/InitInstance (new window class)
