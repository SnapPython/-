% 二分法求解非线性方程的近似根
% a: 区间左端点
% b: 区间右端点
% tol: 收敛容差
% max_iter: 最大迭代次数

function [root, iter] = bisection_method(a, b, tol, max_iter)

if func(a) * func(b) >= 0
    error('区间两端点函数值乘积需小于0');
end

iter = 0;
while (b - a) > tol && iter < max_iter
    c = (a + b) / 2;
    if func(c) == 0
        root = c;
        return;
    elseif func(c) * func(a) < 0
        b = c;
    else
        a = c;
    end
    iter = iter + 1;
end

root = (a + b) / 2;
if iter == max_iter
    warning('达到最大迭代次数');
end
end

% 用于二分法
% func(x) 要求解的非线性方程
function y = func(x)
y = x^3 + 4*x^2 - 10;
end
