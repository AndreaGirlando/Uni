# rappresentazione del moto di un punto materiale soggetto a
# 1 forza peso
# 2 forza di resistenza viscosa

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Parametri fisici
m = 1.0                 # massa (kg)
g = 9.81                # accelerazione gravitazionale (m/s^2)
beta = 2.0              # coefficiente viscoso (kg/s)
y0 = 22.0               # posizione iniziale (m)

# Costanti derivate
v_lim = -m * g / beta
alpha = beta / m

# Funzioni del moto (velocità e legge oraria)
def v(t):
    return v_lim * (1 - np.exp(-alpha * t))

def y(t):
    return y0 + v_lim * (t + (1 / alpha) * (np.exp(-alpha * t) - 1))

# Tempo di volo
t_max = 5
fps = 30
frames = int(t_max * fps)
t_vals = np.linspace(0, t_max, frames)
y_vals = y(t_vals)
v_vals = v(t_vals)

# Setup figura
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

# Subplot caduta
ax1.set_xlim(-1, 1)
ax1.set_ylim(0, y0 + 1)
ax1.set_title("Caduta del punto materiale")
ax1.set_xlabel("x (fisso)")
ax1.set_ylabel("y (m)")
punto, = ax1.plot(0, y0, 'bo', markersize=10)

# Subplot v(t)
ax2.set_xlim(0, t_max)
ax2.set_ylim(1.1 * v_lim, 1)
ax2.set_title("Velocità v(t)")
ax2.set_xlabel("Tempo (s)")
ax2.set_ylabel("v (m/s)")
ax2.plot(t_vals, v_vals, 'r-', label='v(t)')
punto_v, = ax2.plot(0, v_vals[0], 'ko', markersize=6)
ax2.legend()

# Funzione di aggiornamento
def update(frame):
    t = t_vals[frame]
    y_pos = y_vals[frame]
    v_val = v_vals[frame]
    punto.set_data([0], [y_pos])
    punto_v.set_data([t], [v_val])

    return punto, punto_v

ani = animation.FuncAnimation(fig, update, frames=frames, interval=1000/fps, blit=True)
# Salvataggio come GIF 
# ani.save("caduta_viscosa.gif", writer='pillow', fps=fps)

plt.tight_layout()
plt.show()
