import requests
import json

url = 'http://apis.data.go.kr/1480523/MetalMeasuringResultService/MetalService'

params = {
    'serviceKey' : 'HXUhE5j8RSzIdn4qILZY1ZPVAaCRmWNJS1/HV+Uj+0bt7NVqRJNbRH6zDEc9pv7cuLSdrrCDCP9E2k+MjFE24w==',
    'pageNo' : '1',
    'numOfRows' : '12',
    'resultType' : 'json',
    'date' : '20220601',
    'stationcode' : '9',
    'itemcode' : '90303',
    'timecode' : 'RH02'
}

response = requests.get(url, params=params)
result = json.loads(response.content.decode())

print(result)
for index, item in enumerate(result["MetalService"]["item"]):
    val = item["VALUE"]
    print(f"{index+1} {val}")