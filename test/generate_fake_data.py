import pandas as pd
import numpy as np
from datetime import datetime, timedelta

# Generate fake data
num_entries = 100
start_date = datetime.strptime("01-01-2025", "%m-%d-%Y")
date_list = [start_date + timedelta(days=i*7) for i in range(num_entries)]  # Weekly entries

amount_spent_list = np.random.uniform(50, 150, num_entries).round(2)
btc_price_list = np.random.uniform(30000, 60000, num_entries).round(2)

btc_purchased_list = (amount_spent_list / btc_price_list).round(6)
total_invested_list = np.cumsum(amount_spent_list).round(2)
total_btc_list = np.cumsum(btc_purchased_list).round(6)
dca_list = (total_invested_list / total_btc_list).round(6)

# Create a DataFrame
data = {
    "Date": [date.strftime("%m-%d-%Y") for date in date_list],
    "Amount Spent ($)": amount_spent_list,
    "BTC Purchased (BTC)": btc_purchased_list,
    "Bitcoin Price ($)": btc_price_list,
    "Total Amount Invested ($)": total_invested_list,
    "Total BTC Purchased (BTC)": total_btc_list,
    "DCA ($ per BTC)": dca_list
}

df = pd.DataFrame(data)

# Save to CSV
csv_file_path = "btc_dca_fake_data.csv"
df.to_csv(csv_file_path, index=False)

print(f"Fake data generated and saved to {csv_file_path}")