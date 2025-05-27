import requests

def decode_secret_message(url):
  #get data from the url
  response = requests.get(url)
  if(response.status_code == 200):
    content = response.text
    print(content)
  else:
    print("failed to read the file: " + url)
    raise requests.excpetions.RequestException("failed to read the file")
    
  #read the data into a df
  df = pd.read_csv(io.StringIO(respone.text), sep='\t')
  print(df)