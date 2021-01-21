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
    local q, pre, v, t, i, m;
    q := Set([]);
    pre := NewDictionary(Int, true, BooleanFamily);
    m := set[1];
    AddSet(q, x);
    while Length(q) <> 0 do
        v := q[Length(q)];
        RemoveSet(q, v);
        if KnowsDictionary(pre, v) then
            continue;
        fi;
        AddDictionary(pre, v, true);

        for i in set do
            if i >= v then
                break;
            fi;

            t := v-i;

            if t < m then
                break;
            fi;

            if KnowsDictionary(ht, t) then
                return false;
            fi;

            if not KnowsDictionary(pre, t) then
                AddSet(q, t);
            fi;
        od;
    od;
    return true;
end;

FindMinimalSet := function(set)
    local ht, l, i, x, res;
    ht := RemoveMultiples(set);
    l := Length(set);
    for i in [l, (l-1)..1] do
        x := set[i];
        res := TestMinimality(set, x, ht);
        if not res then
            RemoveSet(set, x);
        fi;
    od;
end;
