function y_interp = newton_interpolation(x, y, x_interp)
% x: 已知数据点的横坐标向量
% y: 已知数据点的纵坐标向量
% x_interp: 需要插值的横坐标点向量

n = length(x);
% 构建差商表，初始化为与y相同的大小
difference_quotient_table = zeros(n, n);
difference_quotient_table(:, 1) = y;

% 计算差商表
for j = 2:n
    for i = 1:(n - j + 1)
        difference_quotient_table(i, j) = (difference_quotient_table(i + 1, j - 1) - difference_quotient_table(i, j - 1)) / (x(i + j - 1) - x(i));
    end
end

% 计算插值点的值
y_interp = zeros(size(x_interp));
for k = 1:length(x_interp)
    x_val = x_interp(k);
    sum_term = difference_quotient_table(1, 1);
    product_term = 1;
    for m = 1:(n - 1)
        product_term = product_term * (x_val - x(m));
        sum_term = sum_term + difference_quotient_table(1, m + 1) * product_term;
    end
    y_interp(k) = sum_term;
end