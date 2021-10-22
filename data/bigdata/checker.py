import sys

print(sys.argv)

if len(sys.argv) < 3:
    print("Need two args")
else:
    f1 = open(sys.argv[1])
    # print("ground truth file is {}".format(sys.argv[1]))
    f2 = open(sys.argv[2])
    # print("your answer file is {}".format(sys.argv[2]))

    answer_lines = f1.readlines()
    submit_lines = f2.readlines()

    if len(answer_lines) != len(submit_lines):
        print("files line cannot match")
        exit(0)

    length = len(answer_lines)

    final_score = 0.0

    for i in range(length):
        right_count = 0
        wrong_count = 0
        miss_count = 0
        answer_count = 0
        submit_count = 0
        answer_set = set()
        answer_set.clear()
        submit_set = set()
        submit_set.clear()

        if answer_lines[i].strip() != "":
            answer = sorted(list(map(lambda x: int(x), answer_lines[i].strip().split(" "))))
            for sw in answer:
                answer_set.add(sw)
        answer_count = len(answer_set)
        if submit_lines[i].strip() != "":
            submit = sorted(list(map(lambda x: int(x), submit_lines[i].strip().split(" "))))
            for bm in submit:
                submit_set.add(bm)
        submit_count = len(submit_set)
        right_set = answer_set & submit_set
        right_count = len(right_set)
        wrong_count = submit_count - right_count
        miss_count = answer_count - right_count

        if right_count + miss_count + wrong_count != 0:
            rate = (right_count * 1.0) / (right_count * 1.0 + miss_count * 1.0 + wrong_count * 1.0)
        else:
            rate = 1.0

        if answer_count < 20:
            if rate > 0.8:
                score = rate
            elif rate > 0.5:
                score = rate / 2.0
            else:
                score = -(1.0 - rate)
        else:
            if rate > 0.9:
                score = rate
            elif rate > 0.6:
                score = rate / 2.0
            else:
                score = -(1.0 - rate)

        final_score += score

        '''
        # for debug
        print(i, answer_count, submit_count, right_count, miss_count, wrong_count, score)
        if miss_count > 0:
            print(i, answer_set - submit_set)
        if wrong_count > 0:
            print(i, submit_set - answer_set)
        '''

    final_score /= (length * 1.0)
    if final_score < 0.9:
        final_score = 0

    print("accuracy score: %.4f" % final_score)

