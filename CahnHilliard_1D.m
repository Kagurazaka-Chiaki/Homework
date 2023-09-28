function [x, t, Phi] = CahnHilliard_1D()
    D = @(Phi) spdiags(ddF(Phi), 0, length(Phi), length(Phi));
    x = linspace(0, L, P + 1);
    t = linspace(0, T, N + 1);
    Dx = L / P;
    Dt = T / N;
    o = ones(P + 1, 1);
    A = spdiags([-o, 2 * o, -o], [-1, 0, 1], P + 1, P + 1);
    A(1, 2) = -2;
    A(end, end - 1) = -2;
    A = A / Dx^2;
    Phi = zeros(P + 1, N + 1);
    I = speye(P + 1);
    Phi(:, 1) = phi_0(x);
    U0 = I + kappa * (epsilon^2) * Dt * A^2 + kappa * Dt * A * D(Phi(:, 1));
    DU0 = decomposition(U0, "auto");
    Phi(:, 2) = DU0 \ Phi(:, 1);
    for n = 3:1:(N + 1)
        U = (3/2) * I + kappa * (epsilon^2) * Dt * A^2 + kappa * Dt * A * D(Phi(:, n - 1));
        DU = decomposition(U, "auto");
        RHS = 2 * Phi(:, n - 1) - (1/2) * Phi(:, n - 2) - kappa * Dt * A * (dF(Phi(:, n - 1)) - D(Phi(:, n - 1)) * Phi(:, n - 1));
        Phi(:, n) = DU \ RHS;
    end
end