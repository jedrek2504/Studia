from lib.xlsxReader import data_labels


def get_training_data(data):
    static_training = []
    static_target = []

    for room in ["f8", "f10"]:
        for key, val in enumerate(data[room]["static"]["s"]):
            for i in range(len(val)):
                tmp_training = list(val[i].values())
                tmp_target = tmp_training[-2:]
                tmp_training = tmp_training[:-2]

                if any(x in tmp_training for x in [None, ""]):
                    continue

                if len(tmp_training) != len(data_labels) - 2:
                    tmp_training.pop()
                static_training.append(tmp_training)
                static_target.append(tmp_target)
    return static_training, static_target


def get_verification_data(data):
    dynamic_training = []
    dynamic_target = []

    for room in ["f8", "f10"]:
        for data_type in ["dynamic", "random"]:
            for turn in ["p", "z"]:
                for key, val in enumerate(data[room][data_type][turn]):
                    for i in range(len(val)):
                        tmp_training = list(val[i].values())
                        tmp_target = tmp_training[-2:]
                        tmp_training = tmp_training[:-2]

                        if any(x in tmp_training for x in [None, ""]):
                            continue

                        if len(tmp_training) != len(data_labels) - 2:
                            continue
                        dynamic_training.append(tmp_training)
                        dynamic_target.append(tmp_target)
    return dynamic_training, dynamic_target
