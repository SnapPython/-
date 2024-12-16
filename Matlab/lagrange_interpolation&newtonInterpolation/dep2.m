x = [1, 4, 9]; 
y = [1, 2, 3]; 
x_interp = 5;

tic;
y_interp = newton_interpolation(x, y, x_interp);
elapsed_time = toc;

disp(y_interp);
disp(['代码运行时间为 ', num2str(elapsed_time),'秒']);