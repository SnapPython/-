function y_interp = lagrange_interpolation(x, y, x_interp)
% x: 已知数据点的横坐标向量
% y: 已知数据点的纵坐标向量
% x_interp: 需要插值的横坐标点向量

n = length(x);
y_interp = zeros(size(x_interp));

for k = 1:length(x_interp)
    x_val = x_interp(k);
    sum_term = 0;
    for i = 1:n
        li = 1;
        for j = 1:n
            if j ~= i
                li = li * (x_val - x(j)) / (x(i) - x(j));
            end
        end
        sum_term = sum_term + y(i) * li;
    end
    y_interp(k) = sum_term;
end