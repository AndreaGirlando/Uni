import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider

g = 9.81

def trajectory(v0, theta_deg, y0=0.0, npts=400):
    th = np.deg2rad(theta_deg)
    vx0, vy0 = v0*np.cos(th), v0*np.sin(th)
    T = (vy0 + np.sqrt(vy0**2 + 2*g*max(y0,0))) / g
    t = np.linspace(0, T, npts)
    x = vx0*t
    y = y0 + vy0*t - 0.5*g*t**2
    return x, y, T, vx0, vy0

#------------------------------------------------------------------------------
# CONDIZIONE INIZIALE
# Fissa la condizione iniziale per il primo plot.
# La condizione iniziale è poi modificabile tramite slider interattivo. 
#------------------------------------------------------------------------------
v0_init   = 20.0    # velocità iniziale in m/s
theta_init = 45.0   # angolo iniziale in gradi (è convertito in radianti dopo)
y0 = 10.0    # quota iniziale in m

# figura + assi
fig, ax = plt.subplots()
plt.subplots_adjust(left=0.12, bottom=0.25)  # spazio per sliders

x, y, T, vx0, vy0 = trajectory(v0_init, theta_init, y0)
[line] = ax.plot(x, y, lw=2)
# apice
tA = vy0/g
apex_x, apex_y = vx0*tA, y0 + vy0*tA - 0.5*g*tA**2
apex, = ax.plot([apex_x], [apex_y], 'o')

ax.set_xlabel("x [m]")
ax.set_ylabel("y [m]")
ax.grid(True)
ax.set_aspect("equal", adjustable="datalim")
ax.set_title(f"v0={v0_init:.1f} m/s, θ={theta_init:.1f}°,\n"
             f"tempo di volo={T:.2f}s, gittata={x[-1]:.2f} m")

# slider per v0
ax_v0 = plt.axes([0.12, 0.14, 0.76, 0.03])
s_v0 = Slider(ax=ax_v0, label="v0 [m/s]", valmin=1, valmax=80, valinit=v0_init, valstep=1)

# slider per theta
ax_th = plt.axes([0.12, 0.08, 0.76, 0.03])
s_th = Slider(ax=ax_th, label="θ [°]", valmin=1, valmax=89, valinit=theta_init, valstep=1)

def update(val):
    v0 = s_v0.val
    theta = s_th.val
    x, y, T, vx0, vy0 = trajectory(v0, theta, y0)
    line.set_data(x, y)

    # aggiorna apice
    tA = vy0/g
    axp, ayp = vx0*tA, y0 + vy0*tA - 0.5*g*tA**2
    apex.set_data([axp], [ayp])

    # aggiorna titolo e limiti
    ax.set_title(f"v0={v0:.1f} m/s, θ={theta:.1f}°,\n"  
                 f"tempo di volo={T:.2f}s, gittata={x[-1]:.2f} m")
    ax.relim(); ax.autoscale_view()  # ridimensiona se serve
    fig.canvas.draw_idle()

s_v0.on_changed(update)
s_th.on_changed(update)

plt.show()
