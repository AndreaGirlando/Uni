# PROBLEMA PROIETTILE INTERCETTA MELA

import numpy as np
import matplotlib
try:
    matplotlib.use("QtAgg")
except Exception:
    matplotlib.use("Qt5Agg")
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button
#from math import sqrt

g = 9.81
X, H = 30.0, 12.0
R = np.hypot(X, H)
ux, uy = X/R, H/R

t_ground = np.sqrt(2*H/g)
vmin = R / t_ground

def projectile_pos(v0, t):
    return v0*ux*t, v0*uy*t - 0.5*g*t*t

def apple_pos(t):
    return X, H - 0.5*g*t*t

def hit_time(v0):
    th = R / v0
    yhit = H - 0.5*g*th*th
    return th if yhit >= 0 else None

# ---- FIGURA ----
fig, ax = plt.subplots()
plt.subplots_adjust(left=0.12, bottom=0.28)

# Tempo massimo fisso per il disegno 
TMAX = max(t_ground, R/max(vmin, 10.0)) * 1.3
tt = np.linspace(0, TMAX, 500)

# curve iniziali
v0_init = max(vmin*1.05, 20.0)
xp, yp = projectile_pos(v0_init, tt)
xa = np.full_like(tt, X)
ya = H - 0.5*g*tt*tt

traj_p, = ax.plot(xp[yp>=0], yp[yp>=0], lw=2, label="Proiettile")
traj_a, = ax.plot(xa[ya>=0], ya[ya>=0], lw=2, label="Mela")

# marker istantanei
px0, py0 = projectile_pos(v0_init, 0.0)
axp, = ax.plot([px0], [max(py0,0)], 'o', label="Proiettile @ t")
xa0, ya0 = apple_pos(0.0)
axa, = ax.plot([xa0], [max(ya0,0)], 's', label="Mela @ t")

# punto d’impatto
hit_pt, = ax.plot([], [], 'X', ms=8, label="Impatto")

# linea di mira
ax.plot([0, X], [0, H], ':', alpha=0.6, label="Linea di mira")

ax.set_xlabel("x [m]"); ax.set_ylabel("y [m]")
ax.grid(True); ax.set_aspect("equal", adjustable="datalim")
ax.set_xlim(0, X*1.1); ax.set_ylim(bottom=0)
ax.legend(loc="best")
title = ax.set_title("")

#---- SLIDERS 
ax_v0 = plt.axes([0.12, 0.20, 0.76, 0.03])
s_v0  = Slider(ax=ax_v0, label="v0 [m/s]", valmin=1, valmax=120,
               valinit=v0_init, valstep=0.5, initcolor='none')

ax_t  = plt.axes([0.12, 0.14, 0.76, 0.03])
s_t   = Slider(ax=ax_t,  label="t [s]",   valmin=0.0, valmax=TMAX,
               valinit=0.0, valstep=0.01, initcolor='none')



YTOP = H * 1.1
ax.set_ylim(0, YTOP)

# pulsante reset
ax_reset = plt.axes([0.82, 0.06, 0.12, 0.05]); btn_reset = Button(ax_reset, 'Reset')

def update(_):
    v0 = s_v0.val
    t  = s_t.val

    # ridisegna le curve di riferimento con lo stesso tt (TMAX fisso)
    xp, yp = projectile_pos(v0, tt)
    xa = np.full_like(tt, X); ya = H - 0.5*g*tt*tt
    traj_p.set_data(xp[yp>=0], yp[yp>=0])
    traj_a.set_data(xa[ya>=0], ya[ya>=0])

    # posizioni istantanee
    px, py = projectile_pos(v0, t)
    axp.set_data([px], [max(py,0)])
    xa_t, ya_t = apple_pos(t)
    axa.set_data([xa_t], [max(ya_t,0)])

    # impatto (se avviene prima del suolo)
    th = hit_time(v0)
    if th is not None:
        xi, yi = projectile_pos(v0, th)
        hit_pt.set_data([xi], [yi])
        title.set_text(f"v0={v0:.1f} m/s — t_hit={th:.2f} s,  y_hit={yi:.2f} m")
    else:
        hit_pt.set_data([], [])
        title.set_text(f"v0={v0:.1f} m/s — troppo lento (v_min≈{vmin:.1f} m/s)")

     
    ax.set_xlim(left=0)
    ax.set_ylim(0, YTOP)
    fig.canvas.draw_idle()

def do_reset(_):
    s_v0.set_val(v0_init)
    s_t.set_val(0.0)

s_v0.on_changed(update)
s_t.on_changed(update)
btn_reset.on_clicked(do_reset)

update(None)
plt.show()
