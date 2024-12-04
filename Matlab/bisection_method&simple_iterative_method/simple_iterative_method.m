function [root, iter] = simple_iterative_method(x0, tol, max_iter)
    % 一般迭代法求解非线性方程近似根
    % x0: 初始值
    % tol: 收敛容差
    % max_iter: 最大迭代次数

    iter = 0;
    x = x0;
    while iter < max_iter
        x_new = g(x);
        if abs(x_new - x) < tol
            root = x_new;
            return;
        end
        x = x_new;
        iter = iter + 1;
    end
    root = x;
    if iter == max_iter
        warning('达到最大迭代次数，可能未精确收敛');
    end
end

% 定义迭代函数
function y = g(x)
    y = (10 / (x + 4)) ^ (1 / 2);  
end