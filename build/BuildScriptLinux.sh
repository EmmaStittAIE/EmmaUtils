#!/usr/bin/env sh

function FailedPremake {
    echo ""
    echo "---Premake Failed---"
    echo ""

    echo "Premake5 was not able to generate project files"

    exit 2
}

function FailedBuild {
    echo ""
    echo "---Build Failed---"
    echo ""

    echo "Make was not able to build project"

    exit 3
}

function PrintHelp {
    echo "Usage: $0 [ -c CONFIG] [ -p PLATFORM ]"
}

# Define default options
config="debug"
platform="linux"

# getopts loop
while getopts "hrdc:p:" options; do

    case "${options}" in

        h)
            PrintHelp
            exit 0
            ;;

        c)
            config=${OPTARG}
            ;;

        p)
            platform=${OPTARG}
            ;;

        *)
            PrintHelp
            exit 1
            ;;
    esac
done

buildConfig="${config,,}_${platform,,}"

echo "---Build Start---"

echo ""
echo "---Building Projects---"
echo ""

# Premake
echo "Running premake..."
cd ..

if ! premake5 gmake2; then
    FailedPremake
fi

echo "Premake complete"

# Make
echo "Running make"
cd generated


if ! make config=$buildConfig; then
    FailedBuild
fi

echo "Make complete"

echo ""
echo "---Build complete---"
echo ""
