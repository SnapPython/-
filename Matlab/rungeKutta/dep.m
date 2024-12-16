x0 = 0;
y0 = 1;
h = 0.1;
x_end = 1;

[x,y] = runge_kutta(x0,y0,h,x_end);
plot(x,y); 
title('Solution of the ODE using Runge-Kutta Method');
xlabel('x');
ylabel('y');