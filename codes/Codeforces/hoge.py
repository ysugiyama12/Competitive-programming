import requests

params = (
    ('version', '2019-02-28'),
)

response = requests.post('https://gateway.watsonplatform.net/assistant/api/v2/assistants/ASSITANT_ID/sessions',
    params=params, auth=('apikey', 'YOUR-API-KEY'))
print(response)