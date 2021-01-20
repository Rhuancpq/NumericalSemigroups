RemoveMultiples := function(set)
    local max, ht, x, i;
    max := set[Length(set)];
    ht := NewDictionary(Int, true, BooleanFamily);
    for x in set do
        AddDictionary(ht, x, true);
    od;
    for x in set do
        i := x*2;
        while i <= max do
            if KnowsDictionary(ht, i) then
                RemoveSet(set, i);
            fi;
            AddDictionary(ht, x, true);
            i := i+x;
        od;
    od;
    return ht;
    end;

FindApery := function(set)
    local m, count, ap, ht, x, t;
    m := set[1];
    count := 0;
    ap := EmptyPlist(m);
    ht := NewDictionary(Int, true, BooleanFamily);
    for x in set do
        t := x mod m;
        if not KnowsDictionary(ht, t) then
            Add(ap, x);
            AddDictionary(ht, t, true);
            count := count+1;
        fi;
        if count = m then
            break;
        fi;
    od;
    return Set(ap);
end;

TestMinimality := function(set, x, ht)

end;

FindMinimalSet := function(set)
    
end;