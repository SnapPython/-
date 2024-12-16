x = [1.1, 2.3, 3.9, 5.1]; 
y = [3.887, 4.276, 4.651, 2.117]; 

target_x1 = 2.101;
target_x2 = 4.234;

tic;
y_1 = lagrange_interpolation(x, y, target_x1);
y_2 = lagrange_interpolation(x, y, target_x2);
elapsed_time = toc;

disp(y_1);
disp(y_2);
disp(['代码运行时间为 ', num2str(elapsed_time),'秒']);