import pandas as pd
import matplotlib.pyplot as plt

# Load CSV file
csv_file_path = "..\\btc_dca.csv"
df = pd.read_csv(csv_file_path)

# Convert date column to datetime with the correct format
df['Date'] = pd.to_datetime(df['Date'], format='%m-%d-%Y')

# Calculate portfolio value over time
df['Portfolio Value (USD)'] = df['Total BTC Purchased (BTC)'].astype(float) * df['Bitcoin Price ($)'].astype(float)

# Plot the portfolio growth over time
plt.figure(figsize=(14, 8))
plt.plot(df['Date'], df['Portfolio Value (USD)'], label='Portfolio Value (USD)', color='blue', linewidth=2)

# Improve chart aesthetics
plt.title("Portfolio Growth Over Time", fontsize=16, fontweight="bold")
plt.xlabel("Date")
plt.ylabel("Portfolio Value (USD)")
plt.legend(loc="upper left")
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.gca().set_facecolor("#f0f0f0")  # Light background for better contrast

total_usd = df['Portfolio Value (USD)'].iloc[-1]
textstr = f'Total USD: ${total_usd:.6f}'
props = dict(boxstyle='round', facecolor='white', alpha=0.5)
plt.text(0.01, 0.92, textstr, transform=plt.gca().transAxes, fontsize=14,
         verticalalignment='top', bbox=props)

# Save the plot as a PNG file
output_file_path = "Portfolio Growth Over Time in USD ($).png"
plt.savefig(output_file_path, format='png')

# Close the plot to free up memory
plt.close()