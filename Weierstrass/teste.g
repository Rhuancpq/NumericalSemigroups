LoadPackage("Numericalsgps");

g := 10;
maxn := 15;
sns := NumericalSemigroupsWithGenus(g);
gaps := List(sns, x -> GapsOfNumericalSemigroup(x));

# Print(gaps, "\n");

for n in [2..maxn] do
    Print("n: ", n, " ", Float(2*g-1)-Float(g/n), "\n");
od;

# 8 11 17 20 23 26