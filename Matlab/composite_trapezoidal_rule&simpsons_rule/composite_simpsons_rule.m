function result = composite_simpsons_rule(a, b, n)
    h = (b - a) / n;
    x = a:h:b;
    sum1 = 0;
    sum2 = 0;
    for i = 2:2:n-2
        sum1 = sum1 + f(x(i));
    end
    for i = 1:2:n-1
        sum2 = sum2 + f(x(i));
    end
    result = h / 3 * (f(a) + f(b) + 4 * sum2 + 2 * sum1);
end

function y = f(x)
    ind = (x == 0);
    y = sin(x)./(x + (x == 0));
    y(ind) = 1;
end