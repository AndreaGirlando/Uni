# crea una gif animata che confronta la legge oraria versus time
# al variare di theta0.
# produce anche un png statico per un valore di theta0 a scelta


import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp
from matplotlib.animation import FuncAnimation, PillowWriter

# Parametri fisici
g = 9.81
L = 0.1
theta0_list = np.arange(5, 175, 5)  # Da 5° a 170° step 5
t_span = (0, 4)
t_eval = np.linspace(t_span[0], t_span[1], 400)

# Prepara figure
fig, ax = plt.subplots(figsize=(8, 4))
line1, = ax.plot([], [], label='Soluzione completa', 
                 linewidth=1.9, color='#228B22')
line2, = ax.plot([], [], '--', label='Pendolo lineare', 
                 linewidth=1.4, color='#D87093')
ax.axhline(0, color='black', linewidth=0.7)
ax.set_xlim(t_span)
# ax.set_ylim(-200, 200)  # Y-limits fissi per tutti i theta0
ax.set_xlabel("Tempo [s]")
ax.set_ylabel(r"$\theta(t)$ [°]")
ax.grid(True, linestyle=':', linewidth=0.4, alpha=0.4)

ax.legend(loc='upper right')


# Dati vuoti (verranno aggiornati)
theta_nl_all = []
theta_lin_all = []

# Pre-calcolo soluzioni per tutti i theta0
for theta0_deg in theta0_list:
    theta0_rad = np.deg2rad(theta0_deg)
    y0 = [theta0_rad, 0]

    def eq(t, y):
        return [y[1], -(g / L) * np.sin(y[0])]

    sol = solve_ivp(eq, t_span, y0, t_eval=t_eval, method='RK45')
    theta_nl_all.append(np.rad2deg(sol.y[0]))
    theta_lin_all.append(np.rad2deg(theta0_rad * np.cos(np.sqrt(g / L) * sol.t)))

# Funzione di aggiornamento per l'animazione
def update(i):
    theta_nl = theta_nl_all[i]
    theta_lin = theta_lin_all[i]
    theta0_deg = theta0_list[i]
    ax.set_ylim(-1.5 * theta0_deg, 1.5 * theta0_deg)

    line1.set_data(t_eval, theta_nl)
    line2.set_data(t_eval, theta_lin)
    ax.set_title(f"$\\theta_0$ = {theta0_deg}°")
    return line1, line2

# Crea animazione
ani = FuncAnimation(fig, update, frames=len(theta0_list), interval=200, blit=True)

# Salva GIF
ani.save("theta_vs_t_sweep.gif", writer=PillowWriter(fps=5))
print("✅ GIF salvata come 'theta_vs_t_sweep.gif'")


# ----------------------------------
# Grafico statico per theta0 fissato
# ----------------------------------

theta0_deg = 20
theta0_rad = np.deg2rad(theta0_deg)
y0 = [theta0_rad, 0]

# Equazione del pendolo completo
def eq(t, y):
    return [y[1], -(g / L) * np.sin(y[0])]

sol = solve_ivp(eq, t_span, y0, t_eval=t_eval, method='RK45')
theta_nl = np.rad2deg(sol.y[0])
theta_lin = np.rad2deg(theta0_rad * np.cos(np.sqrt(g / L) * sol.t))

# Plot
plt.figure(figsize=(8, 4))
plt.plot(t_eval, theta_nl, label='Soluzione completa', color='#228B22')
plt.plot(t_eval, theta_lin, '--', label='Pendolo lineare', color='#D87093')
plt.axhline(0, color='black', linewidth=0.7)
plt.ylim(-1.5 * theta0_deg, 1.5 * theta0_deg)
plt.xlabel("Tempo [s]")
plt.ylabel(r"$\theta(t)$ [°]")
plt.title(rf"Confronto $\theta(t)$ –- $\theta_0$ = {theta0_deg}°")
plt.grid(True, linestyle=':', linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.savefig(f"confronto_theta_{theta0_deg}.png", dpi=300)
plt.show()

