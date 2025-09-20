import time
import random
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException
from webdriver_manager.chrome import ChromeDriverManager

def fill_google_form(form_url, num_submissions=1):
    """
    Fills a Google Form with random responses multiple times
    
    Args:
        form_url (str): URL of the Google Form
        num_submissions (int): Number of form submissions to make
    """
    # Set up Chrome driver
    options = webdriver.ChromeOptions()
    options.add_argument("--start-maximized")
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
    
    for submission in range(num_submissions):
        # Navigate to the form
        driver.get(form_url)
        print(f"Filling submission {submission + 1}/{num_submissions}")
        
        try:
            # Wait for the form to load
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "form"))
            )
            
            # Handle multiple choice questions (radio buttons)
            radio_questions = driver.find_elements(By.CSS_SELECTOR, 
                                                  "div[role='radiogroup']")
            for question in radio_questions:
                options = question.find_elements(By.CSS_SELECTOR, 
                                               "div[role='radio']")
                if options:
                    random.choice(options).click()
                    time.sleep(0.5)
            
            # Handle checkbox questions
            checkbox_questions = driver.find_elements(By.CSS_SELECTOR, 
                                                     "div[role='list']")
            for question in checkbox_questions:
                checkboxes = question.find_elements(By.CSS_SELECTOR, 
                                                  "div[role='checkbox']")
                if checkboxes:
                    # Select a random number of checkboxes (at least one)
                    num_to_select = random.randint(1, len(checkboxes))
                    selected_boxes = random.sample(checkboxes, num_to_select)
                    for checkbox in selected_boxes:
                        checkbox.click()
                        time.sleep(0.5)
            
            # Handle dropdown menus
            dropdowns = driver.find_elements(By.CSS_SELECTOR, 
                                           "div[role='listbox']")
            for dropdown in dropdowns:
                dropdown.click()
                time.sleep(1)
                options = driver.find_elements(By.CSS_SELECTOR, 
                                             "div[role='option']")
                if options:
                    random.choice(options).click()
                    time.sleep(0.5)
            
            # Handle short answer text fields
            text_fields = driver.find_elements(By.CSS_SELECTOR, 
                                             "input[type='text']")
            for field in text_fields:
                field.send_keys(f"Random answer {random.randint(1, 100)}")
                time.sleep(0.5)
            
            # Handle paragraph text areas
            text_areas = driver.find_elements(By.CSS_SELECTOR, 
                                            "textarea")
            for area in text_areas:
                area.send_keys(f"This is a random paragraph response #{random.randint(1, 100)}. Generated automatically.")
                time.sleep(0.5)
            
            # Submit the form
            submit_button = driver.find_element(By.CSS_SELECTOR, 
                                              "div[role='button'][jsname='M2UYVd']")
            submit_button.click()
            
            # Wait for submission confirmation
            try:
                WebDriverWait(driver, 10).until(
                    EC.presence_of_element_located((By.XPATH, "//*[contains(text(), 'response has been recorded')]"))
                )
                print(f"Submission {submission + 1} completed successfully!")
                time.sleep(2)
            except TimeoutException:
                print(f"Submission confirmation not found, but form may have been submitted.")
        
        except Exception as e:
            print(f"Error during submission {submission + 1}: {e}")
    
    # Close the browser after all submissions
    driver.quit()
    print("All submissions completed!")

if __name__ == "__main__":
    # Replace with your Google Form URL
    form_url = "GOOGLE_FORM_URL"
    
    # Specify how many times to fill and submit the form
    num_submissions = 55
    
    fill_google_form(form_url, num_submissions)