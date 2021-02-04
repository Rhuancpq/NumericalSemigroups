SumTwoSet := function(A, B)
    local res, a, b;    
    res := Set([]);

    for a in A do
        for b in B do
            AddSet(res, a+b);
        od;
    od;

    return res;
end;

SumSet := function(A)
    local res, len, i, j;
    res := Set([]);
    len := Length(A);
    for i in [1..len] do
        for j in [i..len] do
            AddSet(res, A[i]+A[j]);
        od;
    od;

    return res;
end;

SumSetNary := function(set, n, mem) #mem should be a dict
    local res, t;
    if n = 1 then
        return set;
    fi;

    if n mod 2 = 0 then
        t := n/2;
    else
        t := (n-1)/2;
    fi;

    if KnowsDictionary(mem, t) then
        res := LookupDictionary(mem, t);
    else
        res := SumSetNary(set, t, mem);
        AddDictionary(mem, t, res);
    fi;

    if n mod 2 = 0 then
        return SumSet(res);
    else
        return SumTwoSet(SumSet(res), set);
    fi;
end;

# Example of mem
# mem := NewDictionary(Int, true, Set);