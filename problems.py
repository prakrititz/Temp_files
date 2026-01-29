import requests
from openpyxl import Workbook

# =====================================================
# 1. PUT YOUR CODEFORCES PROBLEM LINKS HERE
# =====================================================
PROBLEM_URLS = [
    "https://codeforces.com/problemset/problem/1467/C",
    "https://codeforces.com/problemset/problem/873/D",
    "https://codeforces.com/problemset/problem/1508/B",
    "https://codeforces.com/problemset/problem/1569/B",
    "https://codeforces.com/problemset/problem/82/B",
    "https://codeforces.com/problemset/problem/1659/B",
    "https://codeforces.com/problemset/problem/1621/D",
    "https://codeforces.com/problemset/problem/1762/D",
    "https://codeforces.com/problemset/problem/865/D",
    "https://codeforces.com/problemset/problem/1039/A",
    "https://codeforces.com/problemset/problem/1028/E",
    "https://codeforces.com/problemset/problem/1333/E",
    "https://codeforces.com/problemset/problem/1137/D",
    "https://codeforces.com/problemset/problem/1360/H",
    "https://codeforces.com/contest/364/problem/D",
    "https://codeforces.com/contest/1364/problem/E",
    "https://codeforces.com/contest/442/problem/E",
    "https://codeforces.com/problemset/problem/442/B",
    "https://codeforces.com/contest/817/problem/D",
    "https://codeforces.com/problemset/problem/312/B",
    "https://codeforces.com/problemset/problem/1459/A",
    "https://codeforces.com/problemset/problem/453/A",
    "https://codeforces.com/problemset/problem/268/E",
    "https://codeforces.com/problemset/problem/840/D",
]

# =====================================================
# 2. FETCH ALL PROBLEMS FROM CODEFORCES API
# =====================================================
API_URL = "https://codeforces.com/api/problemset.problems"
resp = requests.get(API_URL).json()

if resp["status"] != "OK":
    raise Exception("Codeforces API failed")

problems = resp["result"]["problems"]

# Map (contestId, index) -> (name, rating)
problem_map = {}
for p in problems:
    cid = p.get("contestId")
    idx = p.get("index")
    if cid and idx:
        problem_map[(cid, idx)] = (
            p.get("name", "N/A"),
            p.get("rating", "N/A")
        )

# =====================================================
# 3. CREATE EXCEL
# =====================================================
wb = Workbook()
ws = wb.active
ws.title = "Codeforces Problems"

ws.append([
    "Problem Link",
    "Contest ID",
    "Index",
    "Problem Name",
    "Rating"
])

# =====================================================
# 4. PARSE LINKS SAFELY + FILL DATA
# =====================================================
for url in PROBLEM_URLS:
    parts = url.strip("/").split("/")

    contest_id = None
    index = None

    try:
        if "problemset" in parts:
            # /problemset/problem/{contestId}/{index}
            contest_id = int(parts[-2])
            index = parts[-1]

        elif "contest" in parts:
            # /contest/{contestId}/problem/{index}
            contest_id = int(parts[parts.index("contest") + 1])
            index = parts[-1]

        else:
            print(f"Skipping unknown format: {url}")
            continue

        name, rating = problem_map.get(
            (contest_id, index),
            ("Not Found", "N/A")
        )

        ws.append([url, contest_id, index, name, rating])

    except Exception as e:
        print(f"Error parsing {url}: {e}")

# =====================================================
# 5. SAVE FILE
# =====================================================
OUTPUT_FILE = "codeforces_problems_with_ratings.xlsx"
wb.save(OUTPUT_FILE)

print(f"\n✅ Excel file created successfully: {OUTPUT_FILE}")
