function result = compound_trapezoidal(a, b, n)
    h = (b - a) / n;
    x = a:h:b;
    if x(1) == 0
        x(1) = 1e-10; 
    end
    sum_middle = 0;
    for i = 2:n 
        sum_middle = sum_middle + sin(x(i)) / x(i);
    end
    result = h / 2 * (sin(x(1)) / x(1) + 2 * sum_middle + sin(x(end)) / x(end));
end