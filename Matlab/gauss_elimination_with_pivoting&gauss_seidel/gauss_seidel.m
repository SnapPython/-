% GAUSS_SEIDEL 使用高斯-赛德尔迭代法求解线性方程组Ax = b
% A: 系数矩阵
% b: 常数项向量
% max_iter: 最大迭代次数
% tol: 收敛容差
% 输出参数:
% x: 方程组的解
% iter: 实际迭代次数

function [x, iter] = gauss_seidel(A, b, max_iter, tol)

n = length(b);
x0 = zeros(n, 1); % 初始解向量
x = x0;
iter = 0;
while iter < max_iter
    x_old = x;
    for i = 1:n
        sum1 = 0;
        sum2 = 0;
        for j = 1:i - 1
            sum1 = sum1 + A(i, j) * x(j);
        end
        for j = i + 1:n
            sum2 = sum2 + A(i, j) * x_old(j);
        end
        x(i) = (b(i) - sum1 - sum2) / A(i, i);
    end
    iter = iter + 1;
    if norm(x - x_old, inf) < tol
        break;
    end
end
if iter == max_iter
    warning('达到最大迭代次数');
end
end