n = int(input())

candy = [list(input()) for _ in range(n)]
visited = [[0] * n for _ in range(n)]

xp = (-1, 0, 1, 0)
yp = (0, -1, 0, 1)

def check(x, y):
    cnt = 0
    for idx in range(4):
        xx = x + xp[idx]
        yy = y + yp[idx]
        if xx < 0 or xx >= n or yy < 0 or yy >= n:
            continue
        if candy[x][y] == candy[xx][yy]:
            continue
        candy[x][y], candy[xx][yy] = candy[xx][yy], candy[x][y]

        if idx == 0 or 3:
            tcnt = 1
            cur = candy[0][y]
            for r in range(1, n):
                if cur == candy[r][y]:
                    tcnt += 1
                else:
                    cur = candy[r][y]
                    cnt = max(cnt, tcnt)
                    tcnt = 1
            cnt = max(cnt, tcnt)

            a = max(x, xx)
            b = min(x, xx)

            for c in range(b, a + 1):
                cur = candy[c][0]
                tcnt = 1
                for r in range(1, n):
                    if cur == candy[c][r]:
                        tcnt += 1
                    else:
                        cur = candy[c][r]
                        cnt = max(cnt, tcnt)
                        tcnt = 1
                cnt = max(cnt, tcnt)
        else:
            tcnt = 1
            cur = candy[x][0]
            for r in range(1, n):
                if cur == candy[x][r]:
                    tcnt += 1
                else:
                    cur = candy[x][r]
                    cnt = max(cnt, tcnt)
                    tcnt = 1
            cnt = max(cnt, tcnt)
            a = max(y, yy)
            b = min(y, yy)
            for c in range(b, a + 1):
                cur = candy[0][c]
                tcnt = 1
                for r in range(1, n):
                    if cur == candy[r][c]:
                        tcnt += 1
                    else:
                        cur = candy[r][c]
                        cnt = max(cnt, tcnt)
                        tcnt = 1
                cnt = max(cnt, tcnt)
        candy[x][y], candy[xx][yy] = candy[xx][yy], candy[x][y]
    return cnt


def init():
    vt = [[0] * n for _ in range(n)]
    icnt = 0
    for i in range(n):
        for j in range(n):
            if vt[i][j] == 1:
                continue
            vt[i][j] = 1
            tt = 1
            cur = candy[i][j]
            for l in range(j+1, n):
                if candy[i][l] == cur:
                    tt += 1
                else:
                    cur = candy[i][l]
                    icnt = max(icnt, tt)
                    tt = 1
            icnt = max(icnt, tt)

            cur = candy[i][j]
            tt = 1
            for l in range(i + 1, n):
                if candy[l][j] == cur:
                    tt += 1
                else:
                    cur = candy[l][j]
                    icnt = max(icnt, tt)
                    tt = 1
            icnt = max(icnt, tt)
    return icnt

ans = init()

for i in range(n):
    for j in range(n):
        if visited[i][j] == 1:
            continue
        visited[i][j] = 1
        ans = max(ans, check(i, j))

print(ans)
