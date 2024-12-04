% 用于二分法
% 设置区间、收敛容差和最大迭代次数
a = 1; 
b = 2; 
tol = 1e-6; % 收敛容差
max_iter = 100; % 最大迭代次数

[root,iter] = bisection_method(a, b, tol, max_iter);
disp(['二分法近似根为：', num2str(root)]);
disp(['二分法迭代次数为：', num2str(iter)]);

% 用于简单迭代法
% 设置初始值、收敛容差和最大迭代次数
x0 = 1; % 初始值
tol = 1e-6; % 收敛容差
max_iter = 100; % 最大迭代次数

[root, iter] = simple_iterative_method(x0, tol, max_iter);
disp(['简单迭代法近似根为：', num2str(root)]);
disp(['简单迭代法迭代次数为：', num2str(iter)]);