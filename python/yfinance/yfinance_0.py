
import yfinance as yahooFinance
import pandas as pd
import datetime

facebookInfo = yahooFinance.Ticker('META')
print(facebookInfo.info)
fileInfo = open(r"C:\dev\git\worldrunsoncode\python\data\info.json", "w+") 
fileInfo.write(str(facebookInfo.info))
fileInfo.close()

pd.set_option('display.max_rows', None)
facebookInfo.history(period="max")
fileHistory = open(r"C:\dev\git\worldrunsoncode\python\data\history.json", "w+") 
fileHistory.write(str(facebookInfo.history(period="max")))
fileHistory.close()

# Valid options are 1d, 5d, 1mo, 3mo, 6mo, 1y,
# 2y, 5y, 10y and ytd.
print(facebookInfo.history(period="6mo"))

#date range
startDate = datetime.datetime(2019, 5, 31)
endDate = datetime.datetime(2021, 1, 30)
print(facebookInfo.history(start=startDate, 
                                     end=endDate))


##
print(facebookInfo.get_institutional_holders())

#news
print(facebookInfo.get_news())
fileNews = open(r"C:\dev\git\worldrunsoncode\python\data\news.json", "w+") 
fileNews.write(str(facebookInfo.get_news()))
fileNews.close()

#recommendations
print(str(facebookInfo.get_recommendations()))



# CREATE A TICKER INSTANCE PASSING TESLA AS THE TARGET COMPANY
tsla = yahooFinance.Ticker('TSLA')

# CALL THE MULTIPLE FUNCTIONS AVAILABLE AND STORE THEM IN VARIABLES.
actions = tsla.get_actions()
analysis = tsla.get_analyst_price_target
balance = tsla.get_balance_sheet()
calendar = tsla.get_calendar()
cf = tsla.get_cashflow()
info = tsla.get_info()
inst_holders = tsla.get_institutional_holders()
news = tsla.get_news()
recommendations = tsla.get_recommendations()

# PRINT THE RESULTS
print(actions)
print('*'*20)
print(analysis)
print('*'*20)
print(balance)
print('*'*20)
print(calendar)
print('*'*20)
print(cf)
print('*'*20)
print(info)
print('*'*20)
print(inst_holders)
print('*'*20)
print(news)
print('*'*20)
print(recommendations)
print('*'*20)

# FETCH OPTIONS CHAIN DATA FOR THE COMPANY
tsla_options = tsla.option_chain()

# ACCESS BOTH THE CALLS AND PUTS AND STORE THEM IN THEIR RESPECTIVE VARIABLES
tsla_puts = tsla_options.puts
tsla_calls = tsla_options.calls

tsla_puts
tsla_calls
