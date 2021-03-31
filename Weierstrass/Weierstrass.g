LoadPackage("Numericalsgps");

# If
# The genus is small (g <= 7)
# The number of generators is small (<= 3) or
# The number of generators is 4 and the last gap is 2g-1 or
# The least positive, a.k.a multiplicity, generator is small (<=5) or
# The weight of semigroup is small (e.g. <=g/2) or
# then the semigroup is realizable like a Weierstrass Semigroup.

IsWeierstrassSemigroup := function(NS)
    local g, w, gen, lg, gapset, p1, p2, p3;

    gapset := Gaps(NS);
    g := Length(gapset);

    if g <= 7 then
        return true;
    fi;
    
    gen := MinimalGenerators(NS);
    lg := gapset[Length(gapset)];

    p1 := Length(gen) <= 3;
    p2 := Length(gen) = 4 and lg = 2*g-1;
    p3 := gen[1] <= 5;

    if p1 or p2 or p3 then
        return true;
    fi;

    w := Weight(NS);
    if w < g/2 then
        return true;
    else
        return false;
    fi;
end;