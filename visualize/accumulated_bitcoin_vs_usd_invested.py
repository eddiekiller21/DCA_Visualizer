import pandas as pd
import matplotlib.pyplot as plt

# Load CSV file
csv_file_path = "..\\btc_dca.csv"
df = pd.read_csv(csv_file_path)

# Convert date column to datetime with the correct format
df['Date'] = pd.to_datetime(df['Date'], format='%m-%d-%Y')

# Calculate BTC purchased in units of BTC
df['Total BTC Purchased (BTC)'] = df['Total BTC Purchased (BTC)'].astype(float)

# Plot the accumulated Bitcoin (in units of BTC) over time
plt.figure(figsize=(14, 8))
plt.step(df['Date'], df['Total BTC Purchased (BTC)'], label='Total BTC Purchased (BTC)', color='orange', linewidth=2, where='post')

# Improve chart aesthetics
plt.title("Accumulated Bitcoin Over Time", fontsize=16, fontweight="bold")
plt.xlabel("Date")
plt.ylabel("Total BTC Purchased (BTC)")
plt.legend(loc="upper left")
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.gca().set_facecolor("#f0f0f0")  # Light background for better contrast

total_btc = df['Total BTC Purchased (BTC)'].iloc[-1]
textstr = f'Total BTC: {total_btc:.6f}'
props = dict(boxstyle='round', facecolor='white', alpha=0.5)
plt.text(0.02, 0.92, textstr, transform=plt.gca().transAxes, fontsize=14,
         verticalalignment='top', bbox=props)

# Save the plot as a PNG file
output_file_path = "Accumulated Bitcoin Over Time.png"
plt.savefig(output_file_path, format='png')

# Close the plot to free up memory
plt.close()