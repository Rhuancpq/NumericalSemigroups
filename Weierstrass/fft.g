CountSumSet := function(A, B)
    ## use fft
end;

SumSetNary := function(set, n, mem) 
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, Set);
    local res, t;
    if n = 1 then
        return set;
    fi;

    if n mod 2 = 0 then
        t := n/2;
    else
        t := n-1;
    fi;

    if KnowsDictionary(mem, t) then
        res := LookupDictionary(mem, t);
    else
        res := SumSetNary(set, t, mem);
        AddDictionary(mem, t, res);
    fi;

    if n mod 2 = 0 then
        return CountSumSet(res, res);
    else
        return CountSumSet(res, set);
    fi;
end;

BuchweitzTest := function(set, min, max)


end;