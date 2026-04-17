import matplotlib.pyplot as plt

# ---------------- DATA ----------------
memory_ml = 5.00
memory_dl = 5852

time_ml = 1.957
time_dl = 18277

# Colors (match your style)
ml_color = "#f5a000"   # orange
dl_color = "#6aa5e3"   # blue

# ---------------- MEMORY PLOT ----------------
plt.figure(figsize=(10,4))

plt.barh(
    ["Machine Learning (ML)", "Deep Learning (DL)"],
    [memory_ml, memory_dl],
    color=[ml_color, dl_color]
)

plt.title("Memory Usage (MB)", fontsize=16)
plt.xlim(0, 6000)

# Value labels
plt.text(memory_ml + 100, 0, f"{memory_ml:.2f} MB", va='center')
plt.text(memory_dl + 100, 1, f"{memory_dl} MB", va='center')

# Reduction text
plt.text(3800, 0.5, "99.91% Reduction",
         fontsize=18, color=ml_color, fontweight='bold')

plt.tight_layout()
plt.savefig("memory_usage.png", dpi=300)
plt.show()


# ---------------- TIME PLOT ----------------
plt.figure(figsize=(10,4))

plt.barh(
    ["Machine Learning (ML)", "Deep Learning (DL)"],
    [time_ml, time_dl],
    color=[ml_color, dl_color]
)

plt.title("Computation Time (Seconds)", fontsize=16)
plt.xlim(0, 20000)

# Value labels
plt.text(time_ml + 500, 0, f"{time_ml:.3f} s", va='center')
plt.text(time_dl + 500, 1, f"{time_dl:,} s", va='center')

# Reduction text
plt.text(13000, 0.5, "99.99% Reduction",
         fontsize=18, color=ml_color, fontweight='bold')

plt.tight_layout()
plt.savefig("computation_time.png", dpi=300)
plt.show()
