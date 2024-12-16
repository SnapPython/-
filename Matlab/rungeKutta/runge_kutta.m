function [x,y] = runge_kutta(x0,y0,h,x_end)
    x = x0;
    y = y0;
    n = floor((x_end - x0) / h) + 1; % 计算步数
    x = zeros(1,n);
    y = zeros(1,n);
    x(1) = x0;
    y(1) = y0;

    for i = 1:n-1
        % 计算k1
        k1 = h * odefcn(x(i), y(i));
        % 计算k2
        k2 = h * odefcn(x(i) + h/2, y(i) + k1/2);
        % 计算k3
        k3 = h * odefcn(x(i) + h/2, y(i) + k2/2);
        % 计算k4
        k4 = h * odefcn(x(i) + h, y(i) + k3);

        % 更新y值
        y(i+1) = y(i) + (k1 + 2*k2 + 2*k3 + k4) / 6;
        % 更新x值
        x(i+1) = x(i) + h;
    end
end

function dydx = odefcn(x,y)
    dydx = x - y + 1;
end