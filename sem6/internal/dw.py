import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

fig, ax = plt.subplots(figsize=(8, 6))

ax.add_patch(Rectangle((0.35, 0.8), 0.3, 0.1, facecolor="lightblue", edgecolor="black"))
ax.text(0.5, 0.85, "DATA SOURCES", ha="center", va="center")

ax.add_patch(
    Rectangle((0.35, 0.6), 0.3, 0.1, facecolor="lightgreen", edgecolor="black")
)
ax.text(0.5, 0.65, "ETL LAYER\n(Extract, Transform, Load)", ha="center", va="center")

ax.add_patch(Rectangle((0.35, 0.4), 0.3, 0.1, facecolor="orange", edgecolor="black"))
ax.text(0.5, 0.45, "DATA WAREHOUSE\n(Facts & Dimensions)", ha="center", va="center")

ax.add_patch(Rectangle((0.35, 0.2), 0.3, 0.1, facecolor="pink", edgecolor="black"))
ax.text(
    0.5,
    0.25,
    "REPORTING / BI TOOLS\n(Excel, Power BI, Tableau)",
    ha="center",
    va="center",
)

ax.annotate(
    "",
    xy=(0.5, 0.8),
    xytext=(0.5, 0.7),
    arrowprops=dict(facecolor="black", shrink=0.05),
)

ax.annotate(
    "",
    xy=(0.5, 0.6),
    xytext=(0.5, 0.5),
    arrowprops=dict(facecolor="black", shrink=0.05),
)

ax.annotate(
    "",
    xy=(0.5, 0.4),
    xytext=(0.5, 0.3),
    arrowprops=dict(facecolor="black", shrink=0.05),
)

ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.axis("off")

plt.show()
