from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome("c:/chromedriver.exe")

#사이트 오픈
driver.get("https://mcdonalds.co.kr")

#요소 값 가져오기
a = driver.find_element(By.CSS_SELECTOR, "#menuList > li:nth-child(3) > a > div.con > strong")
print(a.text)

driver.find_element(By.CSS_SELECTOR, "#commonSearchForm > div > div > button").send_keys(Keys.RETURN)
driver.find_element(By.CSS_SELECTOR, "#commonSearchWord").send_keys("맥너겟")
driver.find_element(By.CSS_SELECTOR, "#commonSearchForm > div > div > fieldset > div > button").click()
driver.find_element(By.CSS_SELECTOR, "#container > div.content > div.contArea > div > div > div:nth-child(3) > div > ul > li:nth-child(2) > a").click()
driver.find_element(By.CSS_SELECTOR, "#container > div.content > div.contArea > div > div > div.viewCon > div:nth-child(1) > button").click()
print(driver.find_element(By.CSS_SELECTOR, "#toggle02 > table > tbody > tr:nth-child(1) > td:nth-child(4)").text)
