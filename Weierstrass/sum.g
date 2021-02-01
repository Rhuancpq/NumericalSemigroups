SumTwoSet := function(A, B)
    local res;
    res := Set([]);

    for a in A do
        for b in B do
            AddSet(res, a+b);
        od;
    od;
end;

SumSet := function(A)
    local res, len;
    res := Set([]);
    len := Length(A);
    for i in [1..len] do
        for j in [i..len] do
            AddSet(res, A[i]+A[j]);
        od;
    od;
end;

SumSetNary := function(set, n)
    if n = 1 then
        return set;
    fi;        

    if n mod 2 = 0 then
        return SumSet(SumSetNary(set, n/2));
    else
        return SumTwoSet(SumSetNary(set, n-1), set);
    fi;
end;
