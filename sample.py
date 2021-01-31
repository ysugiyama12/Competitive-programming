import os
import json
import requests
from github import Github

# Authentication for user filing issue (must have read/write access to
# repository to add issue to)
USERNAME = "omoitsukibot"
PASSWORD = "omoitsuki0129"

# The repository to add this issue to
REPO_OWNER = 'IIS-Lab'
REPO_NAME = 'LightBulb'

token = ""

client = Github(token)
repo = client.get_repo(REPO_OWNER + "/" + REPO_NAME)
issue = repo.create_issue(
    title="TITLE OF THE ISSUE",
    body="TTEXT OF THE ISSUE",
    assignee=USERNAME,
    labels=[
    ]
)

pprint(issue)


def make_github_issue(title, body=None, assignee=None, milestone=None, labels=[]):
    '''Create an issue on github.com using the given parameters.'''
    # Our url to create issues via POST
    url = 'https://api.github.com/repos/%s/%s/issues' % (REPO_OWNER, REPO_NAME)
    print(url)
    # Create an authenticated session to create the issue
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    # Create our issue
    issue = {'title': title,
            'body': body,
            'milestone': milestone,
            'labels': labels}
    # Add the issue to our repository
    r = session.post(url, json.dumps(issue))
    if r.status_code == 201:
        print('Successfully created Issue "{0}"'.format(title))
    else:
        print('Could not create Issue "{0}"'.format(title))
        print(r.status_code)
        print('Response:'+ r.content)

# make_github_issue("title", "this is body",USERNAME,None,[])

